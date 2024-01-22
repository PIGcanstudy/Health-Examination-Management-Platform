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
      <MedicalInfo
        :current-progress="currentProgress"
        :progress-steps="progressSteps"
        :person-info="personInfo"
      />
      <div class="card-header">
          <span>体检项目</span>
      </div>
      <BaseDataList
        :use-form="true"
        :form-data="formData"
        :table-column-attribute="tableColumnAttribute"
        :table-data="tableData"
        />
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
import PeopleList from '@/components/peoplelist/PeopleList-Rom.vue'
import MedicalInfo from '@/components/medicalinfo/MedicalInfo.vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
import { ArrowRightBold, ArrowLeftBold } from '@element-plus/icons-vue'
// PeopleList的变量
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
// MedicalInfo的变量
const currentProgress = ref(1)
const progressSteps = ref(['登记', '在检', '总检', '已完成'])
const personInfo = ref({
  physical_id: '2202401120016',
  id_card: '510521199304017011',
  person_name: 'test-rom',
  sex: '男',
  age: '30',
  physical_type: '健康体检',
  mobile: '18980504604',
  unit_name: 'test-rom',
  marry_type: '',
  type_name: ''
})
// BaseDataList的变量
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
const totalOriginalPrice = tableData.value.reduce((sum, row) => sum + (row.originalPrice || 0), 0);
const totalDiscountPrice = tableData.value.reduce((sum, row) => sum + (row.discountPrice || 0), 0);
// 添加合计行
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
// 本界面变量及函数
const isCollapsed = ref(false)
</script>
<style scoped>
.shrink-button {
  display: flex;
  align-items: center;
  height: 100%;
}
.card-header {
  margin-bottom: 10px;
  display: flex;
  justify-content: center;
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
</style>
