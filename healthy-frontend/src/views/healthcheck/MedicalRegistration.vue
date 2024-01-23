<!-- eslint-disable prettier/prettier -->
<!-- 体检登记 -->
<template>
  <el-container style="height: 100vh;">
    <!-- 侧边栏 -->
    <el-aside :style="{maxWidth: isCollapsed ? '0px' : '300px'}">
      <PeopleList
        :style="isCollapsed ? 'display: none;' : 'min-width: 300px;'"
        :title="title"
        :checkbox-item="checkboxItem"
        :is-date-visible="isDateVisible"
        :external-form-items="formConfig.formItems"
      />
    </el-aside>
    <!-- 伸缩按钮 -->
    <div class="shrink-button">
    <!-- 伸缩按钮 -->
    <el-icon
      style="cursor: pointer; width: 20px;"
      @click="isCollapsed = !isCollapsed"
    >
      <ArrowRightBold v-if="isCollapsed"/>
      <ArrowLeftBold v-else />
    </el-icon>
    </div>
    <!-- 主要内容 -->
    <el-main>
      <!-- 登记信息 -->
      <MedicalInfo
        :current-progress="currentProgress"
        :progress-steps="progressSteps"
        :person-info="personInfo"
        :field-config="fieldConfig"
        :required-fields="requiredFields"
        :on-input-click="checkJob"
      />
      <CheckItems v-if="isCheckItemsVisible" :hide-button="false" :open-drawer="true"/>
      <!-- 按钮区域 -->
      <div style="margin-bottom: 10px;">
        <el-button type="primary" v-if="!isShow" style=" background-color: #ffad33; border-color: #ffad33;" disabled><el-icon style="margin-right: 2px;"><Edit /></el-icon>修改信息</el-button>
        <el-button type="primary" v-if="!isShow" @click="handleSingleAdd">
          <el-icon style="margin-right: 2px;"><Plus /></el-icon>零星新增
        </el-button>
        <el-button type="primary" v-if="!isShow" @click="handleTeamAdd">
          <el-icon style="margin-right: 2px;"><Plus /></el-icon>团检新增
        </el-button>
        <el-button type="primary" v-if="!isShow" style=" background-color: #f16643; border-color: #f16643;" disabled><el-icon style="margin-right: 2px;"><Delete /></el-icon>删除</el-button>
        <el-button type="primary" v-if="isShow" @click="readIdCard">
          <el-icon style="margin-right: 2px;"><Loading v-if="isLoading" class="icon-loading" /><Plus v-else /></el-icon>读取二代身份证
        </el-button>
        <el-button type="primary" v-if="!isShow" @click="printSheet">
          <el-icon style="margin-right: 2px;"><Printer /></el-icon>打印导检单
        </el-button>
        <el-button type="primary" v-if="isShow" @click="savePersonInfo" ><el-icon style="margin-right: 2px;"><CaretRight /></el-icon>保存信息</el-button>
      </div>
      <!-- 体检项目 -->
      <div class="card-header">
          <span>体检项目</span>
          <CheckItems />
      </div>
      <BaseDataList
        ref="baseDataListRef"
        :use-form="true"
        :form-data="formData"
        :table-column-attribute="tableColumnAttribute"
        :table-data="tableData"
        :handle-edit="handleEdit"
      />
      <!-- 操作提示 -->
      <div class="card-content">
        <span>操作说明</span>
        <p>第一步：点击新增</p>
        <p>第二步：填写信息（填写体检人员信息和选择体检项目）</p>
        <p>第三步：点击保存（保存体检人员和体检项目信息）</p>
        <p>第四步：采集人像（采集体检人员头像）</p>
        <p>第五步：确认登记</p>
        <p>第六步：打印导检单（体检人员可以根据导检单进行体检）</p>
        <p>或执行第四、五、六步</p>
      </div>
    </el-main>
  </el-container>
</template>

<script setup>
import { ref } from 'vue'
import { ElMessage } from 'element-plus'
import PeopleList from '@/components/peoplelist/PeopleList-Rom.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import CheckItems from '@/components/checkitems/CheckItems.vue'
import { ArrowRightBold, ArrowLeftBold, Edit, Plus, Delete, Printer, CaretRight, Loading } from '@element-plus/icons-vue'
/* PeopleList的变量 */
const title = ref('人员查询')
const checkboxItem = ref(['未登记', '已登记'])
const isDateVisible = ref(false)
const formConfig = ref({
  formItems: [
    {
      type: 'input',
      name: '',
      placeholder: '请输入身份证号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入体检编号'
    },
    {
      type: 'input',
      name: '',
      placeholder: '请输入单位名称'
    }
  ]
})

/* MedicalInfo的变量 */
const currentProgress = ref(1)
const progressSteps = ref(['登记', '在检', '总检', '已完成'])
const fieldConfig = ref([
      { prop: 'physical_id', label: '体检编号', type: 'input', placeholder: '提交后系统自动生成', disabled: true },
      { prop: 'id_card', label: '身份证号', type: 'input', placeholder: '请输入身份证号', readonly: true },
      { prop: 'person_name', label: '姓名', type: 'input', placeholder: '请输入姓名', readonly: true },
      { prop: 'sex', label: '性别', type: 'input', placeholder: '性别', readonly: true },
      { prop: 'age', label: '年龄', type: 'input', placeholder: '年龄', readonly: true },
      { prop: 'physical_type', label: '体检类型', type: 'input', placeholder: '体检类型', readonly: true },
      { prop: 'mobile', label: '联系电话', type: 'input', placeholder: '联系电话', readonly: true },
      { prop: 'unit_name', label: '单位名称', type: 'input', placeholder: '单位名称', readonly: true },
      { prop: 'hazardous_factors', label: '危害因素', type: 'input', placeholder: '选择套餐后自动生成', disabled: true },
      { prop: 'job_name', label: '工种名称', type: 'input', placeholder: '工种名称', readonly: true, methodBound: true },
      { prop: 'check_type', label: '检查种类', type: 'input', placeholder: '选择套餐后自动生成', disabled: true },
      { prop: 'type_name', label: '分组名称', type: 'select', placeholder: '选择套餐后自动生成', disabled: true, options: [
        { label: '男', value: '男' },
        { label: '女', value: '女' }
      ]},
      { prop: 'marry_type', label: '婚姻状态', type: 'select', placeholder: '请选择', options: [
        { label: '未婚', value: '未婚' },
        { label: '已婚', value: '已婚' },
        { label: '离异', value: '离异' },
        { label: '丧偶', value: '丧偶' },
        { label: '其他', value: '其他' },
      ]}
])
const requiredFields = ref(['id_card','person_name','sex','age','physical_type','mobile','unit_name','job_name'])
const personInfo = ref({
  physical_id: '',
  id_card: '',
  person_name: '',
  sex: '',
  age: '',
  physical_type: '',
  mobile: '',
  unit_name: '',
  hazardous_factors: '',
  job_name: '',
  check_type: '',
  type_name: '',
  marry_type: ''
})

/* BaseDataList的变量 */
const tableColumnAttribute = ref([
  { prop: 'id', label: '#', width: 150, align: 'center' },
  { prop: 'projectName', label: '项目名称', width: 100, align: 'center' },
  { prop: 'originalPrice', label: '原价', width: 150, align: 'center' },
  { prop: 'discount', label: '折扣', width: 250, align: 'center' },
  { prop: 'discountPrice', label: '折扣价', width: 250, align: 'center' },
  { prop: 'projectType', label: '项目类型', width: 250, align: 'center' }
])
const tableData = ref([
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' },
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' },
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' },
  { id: '1', projectName: '肝炎筛查', originalPrice: 188, discount: 0.8, discountPrice: 150.4, projectType: '一号套餐' }
])
// 计算总和
const totalOriginalPrice = tableData.value.reduce((sum, row) => sum + (row.originalPrice || 0), 0)
const totalDiscountPrice = tableData.value.reduce((sum, row) => sum + (row.discountPrice || 0), 0)
tableData.value.push({
  id: '合计',
  projectName: '-',
  originalPrice: totalOriginalPrice,
  discount: '-',
  discountPrice: totalDiscountPrice,
  projectType: '-'
})
const formData = ref({
  id: '',
  projectName: '',
  originalPrice: '',
  discount: '',
  discountPrice: '',
  projectType: ''
})
const baseDataListRef = ref(null)
// 编辑及删除函数
const handleEdit = () => {
  console.log(baseDataListRef.value)
  if (baseDataListRef.value) {
    console.log(baseDataListRef.value.rows) // 访问子组件暴露的 row
  }
}
/* 本界面变量及函数 */
const isCollapsed = ref(false) // 是否收缩侧边栏
const isShow = ref(false) // 是否展示按钮
const isCheckItemsVisible = ref(false) // 是否展示抽屉
const isLoading = ref(false) // 读取身份证图标显示
// 工种名称
const checkJob = () => {
  isCheckItemsVisible.value=!isCheckItemsVisible.value
}
// 零星新增
const handleSingleAdd = () => {
  isShow.value = true
  fieldConfig.value.forEach(field => {
    if (field.readonly) {
      field.readonly = false
    }
  })
}
// 团检新增
const handleTeamAdd = () => {
  isShow.value = true
  fieldConfig.value.forEach(field => {
    if (field.readonly) {
      field.readonly = false
    }
  })
}
// 读取身份证
const readIdCard = () => {
  // 设置 isLoading 为 true
  isLoading.value = true;
  // 3秒后重置 isLoading 状态
  setTimeout(() => {
    isLoading.value = false;
    ElMessage.error("请安装身份证读卡器服务！")
  }, 3000);
}
// 打印导检单
const printSheet = () => {
  ElMessage.warning("正在打印导检单...")
}
// 保存信息
const savePersonInfo = () => {
  isShow.value = false
  fieldConfig.value.forEach(field => {
    if (!field.readonly) {
      field.readonly = true
    }
  })
}

</script>
<style scoped>
.shrink-button {
  display: flex;
  align-items: center;
  height: 100%;
}
.card-header {
  padding-left: 10px;
  margin-bottom: 10px;
  display: flex;
  justify-content: left;
  align-items: center;
  text-align: center;
  background-color: rgb(240, 250, 255);
  border: 1px solid #abdcff;
  height: 40px;

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}
.card-content {
  margin-top: 10px;
  padding: 10px 0 10px 40px;
  text-align: left;
  background-color: rgb(240, 250, 255);
  border: 1px solid #abdcff;

  span {
    color: rgb(81, 90, 110);
    font-weight: 550;
  }
}
.icon-loading{
  animation: rotating 2s infinite linear;
}
@keyframes rotating {
    to {
        transform: rotate(1turn);
    }
}
</style>
