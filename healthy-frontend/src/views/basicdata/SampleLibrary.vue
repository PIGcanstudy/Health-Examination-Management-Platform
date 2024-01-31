<!--
 * @Author: setti5 2283356040@qq.com
 * @Date: 2024-01-30 15:48:01
 * @LastEditors: setti5 2283356040@qq.com
 * @LastEditTime: 2024-01-31 21:00:13
 * @FilePath: \zero-one-healthy-check\healthy-frontend\src\views\basicdata\SampleLibrary.vue
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
<!-- 样本库 -->
<template>
  <div class="container">
    <BaseDataList
      ref="BaseDataRef"
      :use-form="useForm"
      :form-data="formData"
      :table-data="tableData"
      :table-column-attribute="tableColumnAttribute"
      :total="total"
      :use-pagination="usePagination"
      :pagination-data="paginationData"
      :handle-edit="handleEdit"
      :use-fixed="useFixed"
      @update-table-data="handlePageChange"
      @update-selected-rows="selectRows"
    >
      <!-- fixed固定列 -->
      <template #fixed="{ row }">
        <el-button type="primary" style="margin-right: 5px" @click="handelLook(row)">
          <el-icon><View></View></el-icon>
          查看
        </el-button>
        <el-dropdown>
          <el-button>
            更多操作
            <el-icon class="el-icon--right">
              <arrow-down />
            </el-icon>
          </el-button>

          <template #dropdown>
            <el-dropdown-menu>
              <el-dropdown-item>
                <el-icon><Edit></Edit></el-icon>
                修改
              </el-dropdown-item>
              <el-dropdown-item>
                <el-icon><DeleteFilled></DeleteFilled></el-icon>
                删除
              </el-dropdown-item>
            </el-dropdown-menu>
          </template>
        </el-dropdown>
      </template>

      <!-- form搜索表单区域 -->
      <template #form>
        <el-form-item label="名称">
          <el-input v-model="formData.sampleName"></el-input>
        </el-form-item>
        <el-form-item label="标本代码">
          <el-input v-model="formData.sampleCode"></el-input>
        </el-form-item>
        <el-form-item label="关联码">
          <el-input v-model="formData.contactPerson"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary">
            <el-icon><Search></Search></el-icon>
            搜索
          </el-button>
        </el-form-item>
        <el-form-item>
          <el-button @click="resetForm">重置</el-button>
        </el-form-item>
      </template>

      <!-- operation功能区域 -->
      <template #operation>
        <div class="operation">
          <el-button type="primary" style="margin-right: 10px" @click="dialogVisible = true">
            <el-icon><Plus></Plus></el-icon>
            新增
          </el-button>
          <!-- 新增对话框区域 -->
          <el-dialog v-model="dialogVisible" title="新增" width="50%" :before-close="handleClose">
            <el-col>
              <el-form ref="formRef" :model="basicForm" :rules="rules" inline>
                <el-form-item label="名称" :label-width="labelWidth" required>
                  <el-input v-model="basicForm.sampleName" placeholder="请输入名称" style="width: 200px"></el-input>
                </el-form-item>
                <el-form-item label="条码份数" :label-width="labelWidth" required>
                  <el-input v-model="basicForm.barcodeCopies" style="width: 200px"></el-input>
                </el-form-item>
                <el-form-item label="规格" :label-width="labelWidth" required>
                  <el-input v-model="basicForm.specification" placeholder="请输入规格" style="width: 200px"></el-input>
                </el-form-item>
                <el-form-item label="是否采血" :label-width="labelWidth">
                  <el-radio-group v-model="basicForm.isBloodSampling" style="width: 200px">
                    <el-radio label="是" />
                    <el-radio label="否" />
                  </el-radio-group>
                </el-form-item>
                <el-form-item label="标本代码" :label-width="labelWidth" required>
                  <el-input v-model="basicForm.sampleCode" style="width: 200px"></el-input>
                </el-form-item>
                <el-form-item label="排序" :label-width="labelWidth" required>
                  <el-input v-model="basicForm.rank" style="width: 200px"></el-input>
                </el-form-item>
                <el-form-item label="是否打印" :label-width="labelWidth">
                  <el-radio-group v-model="basicForm.isPrint" style="width: 200px">
                    <el-radio label="是" />
                    <el-radio label="否" />
                  </el-radio-group>
                </el-form-item>
                <el-form-item label="关联码" :label-width="labelWidth">
                  <el-input v-model="basicForm.associationCode" style="width: 200px"></el-input>
                </el-form-item>
                <el-form-item label="容量" :label-width="labelWidth">
                  <el-input v-model="basicForm.capacity" style="width: 200px"></el-input>
                </el-form-item>
              </el-form>
            </el-col>

            <template #footer>
              <span class="dialog-footer">
                <el-button @click="dialogVisible = false">取消</el-button>
                <el-button type="primary" @click="dialogVisible = false">提交</el-button>
              </span>
            </template>
          </el-dialog>
          <el-dropdown>
            <el-button style="margin-right: 8px">
              更多操作
              <el-icon class="el-icon--right"> <arrow-down /> </el-icon
            ></el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item>
                  <el-icon><Refresh></Refresh></el-icon>
                  刷新
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon><DeleteFilled></DeleteFilled></el-icon>
                  批量删除
                </el-dropdown-item>
                <el-dropdown-item>
                  <el-icon><Bottom></Bottom></el-icon>
                  导出本页数据
                </el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
          <el-button @click="closeForm">关闭搜索</el-button>
          <el-button @click="closeHint">关闭提示</el-button>
          <el-dropdown style="position: absolute; right: 8px">
            <el-button @click="dynamicList"
              ><el-icon><Operation /></el-icon
            ></el-button>
            <template #dropdown>
              <el-dropdown-menu>
                <el-dropdown-item> 动态列 </el-dropdown-item>
                <el-dropdown-item divided><input type="checkbox" />名称</el-dropdown-item>

                <el-dropdown-item><input type="checkbox" />条码份数</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />规格</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />是否采血</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />标本代码</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />排序</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />是否打印</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />关联码</el-dropdown-item>
                <el-dropdown-item><input type="checkbox" />容量</el-dropdown-item>
              </el-dropdown-menu>
            </template>
          </el-dropdown>
        </div>
      </template>

      <!-- 多选清除栏 -->
      <template #hint>
        <div v-if="useHint" class="hint">
          <span>
            <el-icon style="color: blue"><InfoFilled></InfoFilled></el-icon>
            已选择{{ selectedTotal }}项
          </span>
          <el-button type="primary" link style="margin-bottom: 3px" @click="clearRows">清空</el-button>
        </div>
      </template>
    </BaseDataList>

    <!-- <SampleLibraryForm :title="title"></SampleLibraryForm> -->
  </div>
</template>

<script setup>
import { ref, reactive, onMounted } from 'vue'
import { ArrowDown, Search, Plus, InfoFilled, Refresh, DeleteFilled, Bottom, View, Edit, Operation } from '@element-plus/icons-vue'
import BaseDataList from '@/components/basedatalist/BaseDataList.vue'
// import SampleLibraryForm from '@/views/basicdata/SampleLibrary/SampleLibraryForm.vue'

const selectValue = ref('')
const useHint = ref(true)
const useForm = ref(true)
const usePagination = ref(true)
const BaseDataRef = ref()
const dialogVisible = ref(false)
const useFixed = ref(true)
const labelWidth = '120px'
// table列
const tableColumnAttribute = ref([
  { prop: 'sampleName', label: '名称', width: '200', align: 'center' },
  { prop: 'barcodeCopies', label: '条码份数', width: '120', align: 'center' },
  { prop: 'specification', label: '规格', width: '120', align: 'center' },
  { prop: 'isBloodSampling', label: '是否采血', width: '120', align: 'center' },
  { prop: 'sampleCode', label: '标本代码', width: '120', align: 'center' },
  { prop: 'rank', label: '排序', width: '120', align: 'center' },
  { prop: 'isPrint', label: '是否打印', width: '120', align: 'center' },
  { prop: 'associationCode', label: '关联码', width: '120', align: 'center' },
  { prop: 'capacity', label: '容量', width: '120', align: 'center' }
])
// table数据
const tableData = ref([
  {
    sampleName: '心电图',
    barcodeCopies: '1',
    specification: '留底',
    isBloodSampling: '1',
    sampleCode: '11',
    rank: '1',
    isPrint: '1',
    associationCode: '411',
    capacity: '--'
  },
  {
    sampleName: '基因-话甘宁',
    barcodeCopies: '1',
    specification: '留底',
    isBloodSampling: '0',
    sampleCode: '23',
    rank: '0',
    isPrint: '1',
    associationCode: '143',
    capacity: '--'
  },
  {
    sampleName: '驾驶员体检',
    barcodeCopies: '3',
    specification: ' ',
    isBloodSampling: '1',
    sampleCode: '02',
    rank: '15',
    isPrint: '1',
    associationCode: '155',
    capacity: '--'
  },
  {
    sampleName: '一般检查',
    barcodeCopies: '4',
    specification: '黄管',
    isBloodSampling: '0',
    sampleCode: ' ',
    rank: '23',
    isPrint: '1',
    associationCode: '244',
    capacity: '--'
  },
  {
    sampleName: '肠镜',
    barcodeCopies: '1',
    specification: ' ',
    isBloodSampling: '1',
    sampleCode: '13',
    rank: '24',
    isPrint: '1',
    associationCode: '163',
    capacity: '--'
  },
  {
    sampleName: '乐山市峨边盛和矿业',
    barcodeCopies: '--',
    specification: '健康体检',
    isBloodSampling: '1',
    sampleCode: ' ',
    rank: '2',
    isPrint: '1',
    associationCode: '155',
    capacity: '--'
  },
  {
    sampleName: '乐山市峨边盛和矿业',
    barcodeCopies: '--',
    specification: '健康体检',
    isBloodSampling: '1',
    sampleCode: '44',
    rank: '国有企业',
    isPrint: '1',
    associationCode: '144',
    capacity: '--'
  }
])
function handelLook(row) {
  console.log(row)
}
const formData = reactive({
  sampleName: '',
  sampleCode: '',
  contactPerson: ''
})
// 基础信息表单
const basicForm = reactive({
  sampleName: '',
  barcodeCopies: 0,
  specification: '',
  isBloodSampling: '否',
  sampleCode: '',
  rank: 30,
  isPrint: '否',
  associationCode: '',
  capacity: ''
})

const formRef = ref(null)
const rules = ref({
  sampleName: [{ required: true, message: '名称不能为空!', trigger: 'change' }],
  specification: [{ required: true, message: '规格不能为空!', trigger: 'change' }],
  sampleCode: [{ type: 'date', required: true, message: '标本代码不能为空!', trigger: 'change' }]
})

const closeForm = () => {
  useForm.value = !useForm.value
}
const closeHint = () => {
  useHint.value = !useHint.value
}
// 编辑功能
const handleEdit = (row) => {
  console.log(row)
}
// 显示选中几项
const selectedTotal = ref(0)
// 选中的row
const selectRows = (selectRows) => {
  selectedTotal.value = selectRows.length
  // console.log(selectRows)
  console.log(BaseDataRef.value.rows)
}
// 清空选中行的方法
const clearRows = () => {
  // 调用子组件的 clearSelectedRows 方法
  BaseDataRef.value.clearSelectedRows()
}
// 重置表单方法
const resetForm = () => {
  ;(formData.sampleName = ''), (formData.specification = ''), (formData.contactPerson = ''), (formData.contactPhone = '')
}
const total = tableData.value.length
// 分页参数
const paginationData = ref({
  currentPage: 1,
  pageSize: 5
})
const currentTableData = ref()
// 根据分页参数计算当前显示的数据
function getPagedData(pageSize, currentPage) {
  const start = (currentPage - 1) * pageSize
  const end = start + pageSize
  const tables = []
  for (let i = start; i < end; i++) {
    if (tableData.value[i]) tables.push(tableData.value[i])
  }

  return (currentTableData.value = tables)
}
// 更新分页数据
function handlePageChange(pageSize, currentPage) {
  paginationData.value.pageSize = pageSize
  paginationData.value.currentPage = currentPage
  tableData.value = getPagedData(pageSize, currentPage)
}
onMounted(() => {
  handlePageChange(paginationData.value.pageSize, paginationData.value.currentPage)
})
</script>

<style lang="scss" scoped>
.container {
  width: 100%;
  height: 100%;
  padding: 16px;
}
.operation {
  margin-bottom: 10px;
  display: flex;
}
.hint {
  height: 33px;
  line-height: 33px;
  background-color: rgb(242, 250, 254);
  border: 1px solid rgb(193, 226, 252);
  border-radius: 5px;
  margin-bottom: 10px;
}
.avatar-uploader .avatar {
  width: 178px;
  height: 178px;
  display: block;
}
.avatar-uploader .el-upload {
  border: 1px dashed var(--el-border-color);
  border-radius: 6px;
  cursor: pointer;
  position: relative;
  overflow: hidden;
  transition: var(--el-transition-duration-fast);
}

.avatar-uploader .el-upload:hover {
  border-color: var(--el-color-primary);
}

.el-icon.avatar-uploader-icon {
  font-size: 28px;
  color: #8c939d;
  width: 178px;
  height: 178px;
  text-align: center;
}
</style>
